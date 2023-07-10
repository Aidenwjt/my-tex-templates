#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) 
{
	if(argc != 2)
	{
		printf("Usage: %s FILENAME_NOFILETYPE\n", argv[0]);
		return 0;
	}

	char tex_template[] =
		         "\\documentclass[11pt]{article}\n"
			 "\\usepackage[utf8]{inputenc}\n"
			 "\\usepackage{amssymb}\n"
			 "\\usepackage{amsthm}\n"
			 "\\usepackage{amsmath}\n"
			 "\\usepackage{enumerate}\n"
			 "\\usepackage{fancyhdr}\n"
			 "\\usepackage{hyperref}\n"
			 "\\hypersetup{colorlinks=true,linktoc=all,linkcolor=blue}\n"
			 "\\usepackage[bottom=0.9in,top=0.9in]{geometry}\n\n"
			 "\\newtheorem{theorem}{Theorem}\n"
			 "\\newtheorem{proposition}{Proposition}\n"
			 "\\newtheorem{lemma}{Lemma}\n"
			 "\\newtheorem{corollary}{Corollary}\n"
			 "\\newtheorem{definition}{Definition}\n"
			 "\\newtheorem*{remark}{Remark}\n"
			 "\\newtheorem*{motivation}{Motivation}\n\n"
			 "\\DeclareMathOperator*{\\esssup}{ess\\,sup}\n\n"
			 "\\makeatletter\n"
			 "\\@addtoreset{theorem}{subsection}\n"
			 "\\@addtoreset{proposition}{subsection}\n"
			 "\\@addtoreset{lemma}{subsection}\n"
			 "\\@addtoreset{corollary}{subsection}\n"
			 "\\@addtoreset{definition}{subsection}\n"
			 "\\makeatother\n\n"
			 "\\begin{document}\n"
			 "\\pagestyle{fancy}\n"
			 "\\fancyhead{}\n"
			 "\\fancyhead[L]{\\textbf{Name}}\n"
			 "\\fancyhead[C]{\\textbf{Document Title}}\n"
			 "\\fancyhead[R]{\\textbf{Date}}\n"
			 "\\tableofcontents\n"
			 "\\newpage\n"
			 "\\fancyhead[L]{\\leftmark}\n"
			 "\\fancyhead[C]{}\n"
			 "\\fancyhead[R]{\\rightmark}\n"
			 "\\section{Section Name}\n"
			 "\\subsection{Subsection Name}\n"
			 "Some text\n"
			 "\\end{document}";
	
	char makefile_template[128];
	memset(makefile_template, '\0', sizeof(makefile_template));

	snprintf(
		makefile_template, 
		sizeof(makefile_template),
		"compile:\n\tpdflatex %s.tex\n\tpdflatex %s.tex\n\txdg-open %s.pdf",
		argv[1],argv[1],argv[1]
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
	fp1 = fopen(file_name,"w+");
	fprintf(fp1, "%s", tex_template);
	fclose(fp1);
	fp2 = fopen("Makefile","w+");
	fprintf(fp2, "%s", makefile_template);
	fclose(fp2);
	
	return 0;
}
