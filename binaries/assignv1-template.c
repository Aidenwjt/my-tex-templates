// gcc -o assignv1-template assignv1-template.c
// cd /bin && sudo cp /path/to/assignv1-template .
// sudo chmod +x assignv1-template
// cd && sudo vim .bashrc (append 'export PATH=$PATH:/bin/assignv1-template')

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{
	if(argc != 2)
	{
		printf("Usage: %s FILENAME.tex\n", argv[0]);
		return 0;
	}

	char template[] ="\\documentclass[11pt]{article}\n"
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
			 "\\fancyhead[L]{\\textbf{Name}}\n"
			 "\\fancyhead[C]{\\textbf{Title}}\n"
			 "\\fancyhead[R]{\\textbf{Due Date}}\n"
			 "\\begin{enumerate}[1.]\n"
			 "\\item{[\\textbf{Solution}]} Question description.\n"
			 "Some text\n"
			 "\\end{enumerate}\n"
			 "\\end{document}";

	FILE *fp;
	fp = fopen(argv[1],"w+");
	fprintf(fp, "%s", template);
	fclose(fp);
	
	return 0;
}
