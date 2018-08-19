# Update the web site based on contents of the source repo

# The directory containing a built gpscorrelate. At least 'make docs' must have
# been run here.
BUILDDIR=../gpscorrelate

.PHONY: all update check

all: update check

update:
	cp -fv "$(BUILDDIR)"/doc/*{html,png} .

check: *.html
	tidy -q -e $^
