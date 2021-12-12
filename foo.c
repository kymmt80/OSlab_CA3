int main(int argc, char const *argv[])
{
    int pid;
    for(int i=0;i<5;i++){
        pid=fork();
        if(pid==0)
            break;
    }
    while (1);
    
    return 0;
}
