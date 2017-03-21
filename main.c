#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>


//located at 0xBF8
typedef struct
{
 uint32_t unk0;
 uint32_t NID;
 uint32_t offset;
} ENTRY_TABLE;



int main(int argc, char **argv){
	
	if(argc < 2){
		printf ("\nusage: syslibtrace_extract syslibtable.bin \n");
		return -1;
	}
	
	FILE *fp = fopen(argv[1],"rb");
	
	int i = 0;
	while(i!= 1789){
		
		unsigned char *data_in_buf = (unsigned char*) malloc (12);
		unsigned char *data_in_buf_2 = (unsigned char*) malloc (100);
	
		fseek(fp, 0xBF8 + (12*i), SEEK_SET);
		fread(data_in_buf,12,1,fp);
		
		ENTRY_TABLE* entry_table = (ENTRY_TABLE*)data_in_buf;
		
		//printf("unk0:    0x%X\n", entry_table->unk0);
		printf("0x%X\t", entry_table->NID);
		//printf("offset:     0x%X\n", entry_table->offset);
		//printf("increment:     0x%X\n", i);
		
		entry_table->offset = entry_table->offset - 0x80FFFF60;
		//entry_table->elf_offset = entry_table->elf_offset - 0x81000000;
		
		fseek(fp, entry_table->offset, SEEK_SET);
		fread(data_in_buf_2, 100, 1, fp);
		printf("%s\n", data_in_buf_2);
		free(data_in_buf);
		free(data_in_buf_2);
		
		i++;
	}
	
	fclose(fp);
	
	return 0;
}