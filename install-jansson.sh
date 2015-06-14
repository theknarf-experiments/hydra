#!/bin/sh
set -ex
wget https://github.com/akheron/jansson/archive/master.zip -O /tmp/jansson.zip
cd /tmp/ && unzip jansson.zip
mkdir /tmp/jansson-master/build
cd /tmp/jansson-master/build && cmake .. && make && make check && sudo make install