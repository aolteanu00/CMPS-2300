1) Paging and Address Space
  1. Because we have 20 bits allocated for the Virtual Address Space, we will have 2^20 or 1048576 virtual pages in this system. 28 bits on the right being allocated for the OFFSET means that each page is 2^28 bytes or 256 MB.

  2. The computer has 64 physical frames in physical memory because we have 2^34 bytes of physical memory, and each page is 256 MB.

  3. The system translates from a virtual address to its physical location by using the OFFSET since the offset for the virtual and physical address is the same. We may then use the page table to find the corresponding frame number at the index of the VPN. The physical address we are looking for is the frame number and offset.

2) Address Translation
  4.
    1. 0xB9A9 translates to 0x49A9
    2. 0x0532 translates to 0x7532
    3. 0x6421 translates to 0x8421
    4. 0x1B80 translates to 0xBB80
    5. 0xF300 translates to 0x4313

  5. Since in our page table our page 4 is missing a frame number, a hexadecimal such as 0x4212 could cause a segmentation fault.

3) Page Table Simulation
  6. The change in page-table size should roughly correlate with the growth in address space. Naturally, we will need larger tables to handle more address space.

  7. Changes in page-table size will be inversely correlated with an increase of the size of a page. Naturally, we will need less pages the larger they are.

  8. Using pages that are too large would be inefficient because not every process or program is taxing and demanding of our system. Oversized pages would be complete overkill for the majority of simpler programs.

  9.
    1.0x00003a39
    2.0x00001986

  10. Increasing the percentage of pages that are allocated in each space results in the amount of free space we have decreasing.

  11. When the size of address space exceeds physical memory, the program will no longer function properly. The program will also fail should the page size happen to be larger than the address space size.
