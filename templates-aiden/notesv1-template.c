#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) 
{
	if(argc != 2)
	{
		printf("Usage: %s FILENAME (Excluding file type)\n", argv[0]);
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
			 "\\fancyhead[C]{\\textbf{Document Title}}\n"
			 "\\tableofcontents\n"
			 "\\newpage\n"
			 "\\section{Section Name}\n"
			 "\\subsection{Subsection Name}\n"
			 "Some text\n"
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
	char file_name[64];
	memset(file_name, '\0', sizeof(file_name));
	snprintf(
		file_name, 
		sizeof(file_name),
		"%s.tex",
		argv[1]
	);
	fp1 = fopen(argv[1],"w+");
	fprintf(fp1, "%s", tex_template);
	fclose(fp1);
	fp2 = fopen("Makefile","w+");
	fprintf(fp2, "%s", makefile_template);
	fclose(fp2);
	
	return 0;
}
