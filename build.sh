mkdir build
cd build
cmake ..
cmake --build .

# Path: run.sh
touch run.sh
chmod 777 ./run.sh
echo "cd bin/ && chmod 777 main.o && ./main.o" >> run.sh