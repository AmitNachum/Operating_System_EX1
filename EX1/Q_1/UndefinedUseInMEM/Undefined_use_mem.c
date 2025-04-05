    #include <stdio.h>

    void CauseCarsh();

    void CauseCrash(){

        int *ptr = (int *)0xDEADBEEF;

        *ptr = 40;
    }

    int main(){
        CauseCrash();
        return 0;
    }