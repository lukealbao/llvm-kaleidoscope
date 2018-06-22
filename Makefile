
EMACS	:= /Applications/Emacs.app/Contents/MacOS/Emacs

compiler: compiler.cpp
	clang++ -O3 $< -o $@

compiler.cpp: compiler.org
	/Applications/Emacs.app/Contents/MacOS/Emacs --batch \
	--batch -l org $< -f org-babel-tangle
	./indent.sh $@
	rm -f *~ # Clean temp file from indent script.
