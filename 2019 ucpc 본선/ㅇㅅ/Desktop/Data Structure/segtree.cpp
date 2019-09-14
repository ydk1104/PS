#include <vector>
#include <functional>
#include <utility>

/*
	Usage :
	
	Segtree<Type>( vector, operator, lazy_propagation_operator, identity_element);
	
	vector : Segment tree를 만들 벡터
	operator : Segment tree에서 사용하는 연산자
	lazy_propagation_operator : 해당 연산을 여러 회 반복하는 연산자 ex) 합의 경우 곱, 곱의 경우 제곱.
	identity_element : 해당 연산의 항등원.
	
	Segtree<Type> t(vector); - 합을 구하는 세그먼트 트리
	Segtree<Type> t(vector, [](auto a, auto b) { return a * b; }, [](auto seg, auto lazy, auto l, auto r) { return seg * pow(lazy * (r - l + 1)); }, 1); - 곱을 구하는 세그먼트 트리
	Segtree<Type> t(vector, [](auto a, auto b) { return a ^ b; }, [](auto seg, auto lazy, auto l, auto r) { return (r - l) % 2 ? (seg ^ lazy) : seg; }, 0); - XOR을 구하는 세그먼트 트리
	
	Segtree<pair<Type, Type>> t(vector, [](auto a, auto b) { return pair<Type, Type>(min(a.first, b.fist), max(a.second, b.second)); }, [](auto seg, auto lazy, auto l, auto r) { return pair<Type, Type>(seg.first + (r - l + 1) * lazy, seg.second + (r - l + 1) * lazy); }, pair<Type, Type>(999999, -1)); - 최대-최소를 구하는 세그먼트 트리
	
	t[index] : index 위치에 있는 실제값을 구함. 0-based임.
	t[bound1][bound2] : bound1부터 bound2까지(대소 순서 무관)의 연산값을 구함.
	t[bound1][bound2].lazy(value) : bound1부터 boudn2까지(대소 순서 무관)에 value만큼 lazy propagation을 적용하여 연산함.
	
	t = vector : 해당 연산을 유지한 채로 해당 vector로 새로 Segment tree를 만듦.
	t += vector or Segtree : Segment tree에 해당 vector 또는 Segment Tree의 실제값들을 이어붙임
*/
template<class T>
class Segtree {
private:
	typedef unsigned int Idx;

	Idx _fullSize; // Segment tree를 표현하는데 필요한 총 크기
	Idx _realSize; // 실제 값을 담은 vector의 크기
	Idx _offSet; // 실제 값을 담기 시작하는 위치
	Idx _lazyCnt; // Lazy Propagation이 처리되지 않은 개수

	std::function<T(T, T)> _operator; // Segment tree에서 사용하는 연산
	std::function<T(T, T, Idx, Idx)> _opLazy; // Lazy Propagation에서 사용하는 연산

	std::vector<T> _segTree; // Segment tree vector
	std::vector<T> _segLazy; // Lazy Propagation vector

	T _identityElement; // Segment tree에서 사용하는 연산에 대한 항등원

	static T defLazy(T segVal, T lazyVal, Idx leftChild, Idx rightChild) {
		return segVal + lazyVal * (rightChild - leftChild + 1);
	}

	static T defOp(T segLeft, T segRight) {
		return segLeft + segRight;
	}

public:
	Segtree(Idx size = 0, std::function<T(T, T)> op = defOp, std::function<T(T, T, Idx, Idx)> opLazy = defLazy, T identityElement = 0) { // Segment tree를 주어진 크기로 초기화. 기본값은 빈 트리가 만들어지며, 연산은 더하기, 항등원은 0임
		resize(size);
		_operator = op;
		_opLazy = opLazy;
		_identityElement = identityElement;
		_lazyCnt = 0;
	}
	Segtree(std::vector<T>& data, std::function<T(T, T)> op = defOp, std::function<T(T, T, Idx, Idx)> opLazy = defLazy, T identityElement = 0) : Segtree(data.size(), op, opLazy, identityElement) { // Segment tree를 주어진 vector로 초기화. 기본 연산은 더하기, 항등원은 0임
		buildFromVector(data);
	}
	~Segtree() { _segTree.clear(); }

protected:
	Idx resize(Idx size) { // Segment tree의 실제 값의 크기를 변경
		_realSize = size;
		for (_fullSize = 1; _fullSize < _realSize; _fullSize <<= 1); // Segment tree의 총 크기를 계산
		_fullSize <<= 1;
		_segTree.resize(--_fullSize);
		_segLazy.resize(_fullSize);
		_offSet = _fullSize / 2;
		return _fullSize;
	}
	Idx buildFromVector(std::vector<T>& data) { // Segment tree의 실제 값 vector를 재설정
		resize(data.size());
		for (Idx currentIndex = 0; currentIndex < _fullSize; currentIndex++)
			_segLazy[currentIndex] = _identityElement;
		for (Idx currentIndex = 0; currentIndex < data.size(); currentIndex++) // Segment tree에 실제 값을 대입
			_segTree[_offSet + currentIndex] = data[currentIndex];
		for (Idx currentIndex = _offSet - 1; currentIndex > 0; currentIndex--) // Segment tree의 연산값을 계산
			_segTree[currentIndex] = _operator(_segTree[currentIndex * 2 + 1], _segTree[currentIndex * 2 + 2]);
		_segTree[0] = _operator(_segTree[1], _segTree[2]); // 0-based tree에서는 종료조건을 깔끔하게 설정하기 어려움
		return data.size();
	}

	class Item { // Segment tree의 operator[]을 위한 Delegate class
	protected:
		Idx _offSet;
		Idx _Idx;
		Idx& _lazyCnt;

		std::vector<T>& _segTree;
		std::vector<T>& _segLazy;

		std::function<T(T, T)> _operator;
		std::function<T(T, T, Idx, Idx)> _opLazy;

		T _identityElement;

		class Range {
		protected:
			Idx _leftBound, _rightBound;
			Idx _offSet;
			Idx& _lazyCnt;

			std::vector<T>& _segTree;
			std::vector<T>& _segLazy;

			std::function<T(T, T)> _operator;
			std::function<T(T, T, Idx, Idx)> _opLazy;
			T _identityElement;

			T calc(Idx leftBound, Idx rightBound, Idx currentIndex, Idx currentLeft, Idx currentRight) { // 해당 범위의 연산값을 반환.
				lazyPropagation(currentIndex, currentLeft, currentRight);

				if (leftBound > currentRight || rightBound < currentLeft) return _identityElement;
				if (leftBound <= currentLeft && currentRight <= rightBound) return _segTree[currentIndex];

				return _operator(calc(leftBound, rightBound, currentIndex * 2 + 1, currentLeft, (currentLeft + currentRight) / 2),
					calc(leftBound, rightBound, currentIndex * 2 + 2, (currentLeft + currentRight) / 2 + 1, currentRight));
			}

			void RangeUpdate(T val, Idx leftBound, Idx rightBound, Idx currentIndex, Idx currentLeft, Idx currentRight) { // 해당 범위에 Lazy Propagation
				lazyPropagation(currentIndex, currentLeft, currentRight);

				if (leftBound > currentRight || rightBound < currentLeft) return;
				if (leftBound <= currentLeft && currentRight <= rightBound) {
					_segLazy[currentIndex] = _operator(_segLazy[currentIndex], val);
					_lazyCnt++;
					lazyPropagation(currentIndex, currentLeft, currentRight);
					return;
				}

				RangeUpdate(val, leftBound, rightBound, currentIndex * 2 + 1, currentLeft, (currentLeft + currentRight) / 2);
				RangeUpdate(val, leftBound, rightBound, currentIndex * 2 + 2, (currentLeft + currentRight) / 2 + 1, currentRight);

				_segTree[currentIndex] = _operator(_segTree[currentIndex * 2 + 1], _segTree[currentIndex * 2 + 2]);
			}

			void lazyPropagation(Idx currentIndex, Idx currentLeft, Idx currentRight) { // 자신 자식에게 Lazy Propagation하는 함수.
				if (_segLazy[currentIndex] == _identityElement) return;

				_segTree[currentIndex] = _opLazy(_segTree[currentIndex], _segLazy[currentIndex], currentLeft, currentRight);
				if (currentLeft != currentRight) {
					_segLazy[currentIndex * 2 + 1] = _operator(_segLazy[currentIndex * 2 + 1], _segLazy[currentIndex]);
					_segLazy[currentIndex * 2 + 2] = _operator(_segLazy[currentIndex * 2 + 2], _segLazy[currentIndex]);
					_lazyCnt += 2;
				}

				_segLazy[currentIndex] = _identityElement;
				_lazyCnt--;
			}

		public:
			Range(Idx leftBound, Idx rightBound, Idx offSet, Idx& lazyCnt,
				std::vector<T>& segTree, std::vector<T>& segLazy,
				std::function<T(T, T)> op, std::function<T(T, T, Idx, Idx)> opLazy, T identityElement)
				: _leftBound(leftBound), _rightBound(rightBound), _offSet(offSet), _lazyCnt(lazyCnt),
				_segTree(segTree), _segLazy(segLazy),
				_operator(op), _opLazy(opLazy), _identityElement(identityElement) {
				if (_rightBound < _leftBound) { // 좌우가 뒤집혔을 경우 바로잡음.
					std::swap(_leftBound, _rightBound);
				}
			}
			~Range() { }
			operator T() { // 해당 범위의 연산값을 반환.
				return calc(_leftBound, _rightBound, 0, 0, _offSet);
			}
			void lazy(T val) {
				RangeUpdate(val, _leftBound, _rightBound, 0, 0, _offSet);
			}
		};

		void lazyPropagation(Idx currentIndex, Idx currentLeft, Idx currentRight) { // 자신 자식에게 Lazy Propagation하는 함수.
			if (_segLazy[currentIndex] == _identityElement) return;

			_segTree[currentIndex] = _opLazy(_segTree[currentIndex], _segLazy[currentIndex], currentLeft, currentRight);
			if (currentLeft != currentRight) {
				_segLazy[currentIndex * 2 + 1] = _operator(_segLazy[currentIndex * 2 + 1], _segLazy[currentIndex]);
				_segLazy[currentIndex * 2 + 2] = _operator(_segLazy[currentIndex * 2 + 2], _segLazy[currentIndex]);
				_lazyCnt += 2;
			}

			_segLazy[currentIndex] = _identityElement;
			_lazyCnt--;
		}

		T calc(Idx leftBound, Idx rightBound, Idx currentIndex, Idx currentLeft, Idx currentRight) { // 해당 범위의 연산값을 반환.
			lazyPropagation(currentIndex, currentLeft, currentRight);

			if (leftBound > currentRight || rightBound < currentLeft) return _identityElement;
			if (leftBound <= currentLeft && currentRight <= rightBound) return _segTree[currentIndex];

			return _operator(calc(leftBound, rightBound, currentIndex * 2 + 1, currentLeft, (currentLeft + currentRight) / 2),
				calc(leftBound, rightBound, currentIndex * 2 + 2, (currentLeft + currentRight) / 2 + 1, currentRight));
		}

	public:
		Item(Idx offSet, Idx index, Idx& lazyCnt,
			std::vector<T>& segTree, std::vector<T>& segLazy,
			std::function<T(T, T)> op, std::function<T(T, T, Idx, Idx)> opLazy, T identityElement)
			: _offSet(offSet), _Idx(index), _lazyCnt(lazyCnt),
			_segTree(segTree), _segLazy(segLazy),
			_operator(op), _opLazy(opLazy), _identityElement(identityElement) { }
		~Item() { }
		operator T() { // Segment tree의 해당 Idx 값을 반환
			if (_lazyCnt) {
				calc(_Idx, _Idx, 0, 0, _offSet);
			}
			return _segTree[_Idx + _offSet];
		}
		T& operator =(const T& rb) { // Segment tree의 해당 Idx 값을 설정
			Idx currentIndex = _offSet + _Idx;

			if (_lazyCnt) {
				calc(_Idx, _Idx, 0, 0, _offSet);
			}

			_segTree[currentIndex] = rb;
			while (currentIndex > 0) {
				currentIndex = (currentIndex - 1) >> 1;
				_segTree[currentIndex] = _operator(_segTree[currentIndex * 2 + 1], _segTree[currentIndex * 2 + 2]);
			}
			_segTree[0] = _operator(_segTree[1], _segTree[2]);
			return _segTree[_offSet + _Idx];
		}

		Item& operator =(const Item& rb) { // Segment tree의 해당 Idx 값을 설정
			Idx currentIndex = _offSet + _Idx;
			_segTree[currentIndex] = rb._segTree[rb._Idx + rb._offSet];
			while (currentIndex > 0) {
				currentIndex = (currentIndex - 1) >> 1;
				_segTree[currentIndex] = _operator(_segTree[currentIndex * 2 + 1], _segTree[currentIndex * 2 + 2]);
			}
			_segTree[0] = _operator(_segTree[1], _segTree[2]);
			return *this;
		}

		Range operator[](Idx rightBound) { return Range(_Idx, rightBound, _offSet, _lazyCnt, _segTree, _segLazy, _operator, _opLazy, _identityElement); } // Segment tree에서 주어진 구간의 연산값을 구함
	};

public:
	Item operator[](Idx index) { return Item(_offSet, index, _lazyCnt, _segTree, _segLazy, _operator, _opLazy, _identityElement); } // Segment tree의 해당 Idx 값을 얻어옴
	Idx operator=(std::vector<T>& rb) { return buildFromVector(rb); } // Segment tree의 vector를 재설정
	Idx operator+=(std::vector<T>& rb) { // Segment tree에 vector를 덧붙임
		std::vector<T> newData(_segTree.begin() + _offSet, _segTree.begin() + _offSet + _realSize);
		for (Idx i = 0; i < rb.size(); i++) {
			newData.push_back(rb[i]);
		}
		buildFromVector(newData);

		return _fullSize;
	}

	Idx operator+=(Segtree& rb) { // Segment tree에 vector를 덧붙임
		std::vector<T> newData(_segTree.begin() + _offSet, _segTree.begin() + _offSet + _realSize);
		for (Idx i = 0; i < rb._realSize; i++) {
			newData.push_back(rb._segTree[rb._offSet + i]);
		}
		buildFromVector(newData);

		return _fullSize;
	}

	operator std::vector<T>() { return std::vector<T>(_segTree.begin() + _offSet, _segTree.begin() + _offSet + _realSize); }
};