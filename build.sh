if (test -d "build")
then
    cd build
    cmake ..
    cmake --build .
else 
    # build folder
    mkdir build
    cd build
    cmake ..
    cmake --build .

    # make the run.sh script
    touch run.sh
    chmod 777 ./run.sh
    echo "cd bin/ && chmod 777 main.o && ./main.o" >> run.sh
fi
