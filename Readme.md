#HPM - Hydra package manager
[![Build Status](https://travis-ci.org/whalelang/wpm.svg?branch=master)](https://travis-ci.org/whalelang/wpm)

_Hydra package manager; the cross-platform polyglot version-control-agnostic language package manager for C- and C++-like languages._

## Usage

Create a `wpm.json` file looking like this:

```
{
	"require" : {
		"Catch.zip" : "https://github.com/philsquared/Catch/archive/master.zip",
	  	"Jansson.zip": "https://github.com/akheron/jansson/archive/master.zip",
	  	"libcurl.zip": "http://curl.haxx.se/download/curl-7.42.1.zip"
	}
}
```

and run `wpm install` to get all dependencies.

