.PHONY: all clean
COMANDO=sed '/^NOTE/d' $^ > $@

all: texto.txt

clean:
	rm -f 1_processado.txt 2_processado.txt texto.txt

texto.txt: 1_processado.txt 2_processado.txt
	cat $^ > $@

1_processado.txt: 1.txt
	$(COMANDO)

2_processado.txt: 2.txt
	$(COMANDO)
