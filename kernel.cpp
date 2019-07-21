
// Print a string to the screen in black and white.
void printf(char* str) 
{
    unsigned short* VideoMemory = (unsigned short*)0xb8000;

    // Copy the string to the VideoMemory location.
    for (int i = 0; str[i] != '\0'; ++i)
        VideoMemory[i] = (VideoMemory[i] & 0xFF00) | str[i];
}


// Entry point to the kernel.
extern "C" void kernelMain(void* multiboot_structure, unsigned int magicnumber) 
{
    printf("Hello world!");

    while(1);
}
