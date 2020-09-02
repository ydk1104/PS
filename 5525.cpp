config BR2_PACKAGE_LIBCLI
	bool "libcli"
	help
	  Libcli provides a shared library for including a Cisco-like
	  command- line interface into other software. It's a telnet
	  interface which supports command-line editing, history,
	  authentication and callbacks for a user-definable function
	  tree.

	  http://sites.dparrish.com/libcli