ASM_NAME = asm
CORE_NAME = corewar

all:
	make -C vm/
	make -C assembler/

$(CORE_NAME):
	make -C vm/

$(ASM_NAME):
	make -C assembler/


clean:
	make -C  vm/ clean
	make -C assembler/ clean

fclean: clean
	make -C vm/ fclean
	make -C assembler/ fclean

re: fclean all
