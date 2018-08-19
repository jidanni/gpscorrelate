# Update the web site based on contents of the source repo

# The directory containing a built gpscorrelate. At least 'make docs' must have
# been run here.
BUILDDIR=../gpscorrelate

.PHONY: all update check

all: update check

update:
	cp -fv "$(BUILDDIR)"/doc/*{html,png} "$(BUILDDIR)"/README.md .
	# Convert the file from ISO-8859-1 to ASCII. Github only supports UTF-8 for
	# HTML since it adds a charset=utf-8 header into every response.
	# Ignore errors since tidy doesn't entirely like the source file.
	-tidy -m -q -ascii gpscorrelate.html

check: *.html
	tidy -q -e $^
