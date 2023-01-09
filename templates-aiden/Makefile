all: assignv1-template, notesv1-template

assignv1-template: assignv1-template.c
	gcc -o assignv1-template assignv1-template.c
	sudo cp assignv1-template /bin
	cd /bin
	sudo chmod +x assignv1-template
	cd -
	rm assignv1-template

notesv1-template: notesv1-template.c
	gcc -o notesv1-template notesv1-template.c
	sudo cp notesv1-template /bin
	cd /bin
	sudo chmod +x notesv1-template
	cd -
	rm notesv1-template
