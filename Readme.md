#WPM - Whale package manager

A package manager for languages like C and C++

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

