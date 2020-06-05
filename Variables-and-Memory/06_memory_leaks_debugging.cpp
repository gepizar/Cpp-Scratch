int main() {

    // As we are not calling delete, this generate memory leaks
    int *pInt = new int[10];

    return 0; 
}


/* 

Valgrind -> free. 

        g++ 06_memory_leaks_debugging.cpp

        valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=/home/workspace/valgrind-out.txt /home/workspace/a.out

        cat valgrind-out.txt


Finds the leak in the pointer not deleted.
==21928== LEAK SUMMARY:
==21928==    definitely lost: 40 bytes in 1 blocks

*/ 