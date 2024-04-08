sudo update
sudo apt-get install pulseaudio

mkdir build
cd build
cmake ..
make
cd ..
rm -rf build