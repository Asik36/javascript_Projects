void userArr(){
    int n, randN;
    int *arr , *randArr;
    printf("enter Array size: \n");
    scanf("%d", &n);
    arr = (int*)malloc(n*sizeof(int));
    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d: \n", i+1);
        scanf("%d", arr+i);
    }
    randN = rand()%9;
    randArr = (int*)malloc(randN*sizeof(int));
    for (int i = 0; i < randN; i++)
    {
        if(*(arr+i) == rand()%9)
        *(randArr+i) = rand()%9;
    }

    
}