sudo update
sudo apt-get install pulseaudio

mkdir build
cd build
cmake ..
make
mv ShowTime_0_0_2 ../
cd ..
./ShowTime_0_0_2 2> output
