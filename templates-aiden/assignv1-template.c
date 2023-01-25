// gcc -o assignv1-template assignv1-template.c
// cd /bin && sudo cp /path/to/assignv1-template .
// sudo chmod +x assignv1-template
// cd && sudo vim .bashrc (append 'export PATH=$PATH:/bin/assignv1-template')

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) 
{
	if(argc != 2)
	{
		printf("Usage: %s FILENAME.tex\n", argv[0]);
		return 0;
	}

	char tex_template[] =
			 "\\documentclass[11pt]{article}\n"
			 "\\setlength{\\textwidth}{430pt}\\setlength{\\oddsidemargin}{11pt}\n"
			 "\\usepackage{amssymb}\n"
			 "\\usepackage{amsthm}\n"
			 "\\usepackage{amsmath}\n"
			 "\\usepackage{enumerate}\n"
			 "\\usepackage{fancyhdr}\n"
			 "\\usepackage[bottom=0.9in,top=0.9in]{geometry}\n\n"
			 "\\begin{document}\n"
			 "\\pagestyle{fancy}\n"
			 "\\fancyhead{}\n"
			 "\\fancyhead[L]{\\textbf{Something}}\n"
			 "\\fancyhead[C]{\\textbf{Something}}\n"
			 "\\fancyhead[R]{\\textbf{Something}}\n"
			 "\\begin{enumerate}[1.]\n"
			 "\\item{[\\textbf{Solution}]} Question description.\\\\ \n"
			 "Some text\n"
			 "\\end{enumerate}\n"
			 "\\end{document}";

	char makefile_template[64];
	memset(makefile_template, '\0', sizeof(makefile_template));

	snprintf(
		makefile_template, 
		sizeof(makefile_template),
		"all: compile\n\ncompile:\n\tpdflatex %s\n\txdg-open %s",
		argv[1],argv[1]
	);

	FILE *fp1,*fp2;
	fp1 = fopen(argv[1],"w+");
	fprintf(fp1, "%s", tex_template);
	fclose(fp1);
	fp2 = fopen("Makefile","w+");
	fprintf(fp2, "%s", makefile_template);
	fclose(fp2);
	
	return 0;
}
