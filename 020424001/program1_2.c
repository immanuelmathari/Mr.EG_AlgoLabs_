int main()
{
    int var;
    int* ptr;
    var = 10;
    ptr = &var;

    printf("The value stored at variable var is %d\n", var);
    // dereferencing
    printf("The value stored at variable var is %d\n", *ptr);

    printf("The address of variable var is %p\n", &var);
    printf("The address of variable var is %p\n", ptr);

    return 0;

}