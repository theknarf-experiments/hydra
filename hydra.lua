print("Hello world from lua!");

h = Handler();

h.add_handler();

m = Manifest();

m.add_dependency(--[[ "http://curl.haxx.se/download/curl-7.42.1.zip" ]]);
m.add_dependency(--[[ "https://github.com/philsquared/Catch/archive/master.zip" ]]);
m.add_dependency(--[[ "https://github.com/akheron/jansson/archive/master.zip" ]]);
