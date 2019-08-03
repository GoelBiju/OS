
// Print a string to the screen in black and white.
void printf(char* str) 
{
    static unsigned short* VideoMemory = (unsigned short*)0xb8000;

    // Copy the string to the VideoMemory location.
    for (int i = 0; str[i] != '\0'; ++i)
        VideoMemory[i] = (VideoMemory[i] & 0xFF00) | str[i];
}


typedef void (*constructor)();
extern "C" constructor start_ctors;
extern "C" constructor end_ctors;
extern "C" void callConstructors()
{
    for (constructor* i = &start_ctors; i != &end_ctors; i++)
        (*i)();
}


// Entry point to the kernel.
extern "C" void kernelMain(const void* multiboot_structure, unsigned int /*magicnumber*/) 
{
    printf("Hello Goel!");

    while(1);
}
