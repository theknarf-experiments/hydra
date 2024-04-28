print("Hello world from lua!");

local handle = Handler();

handle:add_handler(--[[ http handler ]]);
handle:add_handler(--[[ zip-file handler ]]);
handle:add_handler(--[[ md5 checksum handler ]]);

local mani = Manifest();

mani:add_handler(handle);

mani:add_dependency{
	name="curl",
	url="http://curl.haxx.se/download/curl-7.42.1.zip",
	checksum="",
};
mani:add_dependency{
	name="catch",
	url="https://github.com/philsquared/Catch/archive/master.zip",
	checksum="",
}
mani:add_dependency{
	name="jansson",
	url="https://github.com/akheron/jansson/archive/master.zip",
	checksum="",
}
