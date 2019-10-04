char s[], f[], fail[]; // s에서 f를 찾기 
void __init__(){
	for(int i=1, j=0; f[i]; i++){
		while(j && f[i] != f[j]) j = fail[j-1];
		if(f[i] == f[j]) fail[i] = ++j;
	}
}

for(int i=0, j=0; s[i]; i++){
	while(j && s[i] != f[j]) j = fail[j-1];
	if(s[i] == f[j]) j++;
	if(!f[j]) j=fail[j-1];
}
