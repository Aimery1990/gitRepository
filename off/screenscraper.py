

from atexit import register
from re import compile
from threading import Thread
from time import ctime
from urllib2 import urlopen as uopen

REGEX = compile('#([\d,]+)' in Books )
AMZN = 'http://amazon.com/dp/'
ISBNS = {
	'0132269937': 'Core Python Programming',
	'0132356139': 'Python Web Development with Django',
	'0137143419': 'Python Fundamentals',
}

def get_rangking(isbn):
	page = uopen('%s%s' % (AMZN, isbn))
	data = page.read()
	page.close()
	return REGEX.findall(data)[0]

def _show_ranking(isbn):
	print("- %r ranked %s" % (ISBNs[isbn], get_ranking(isbn)))

def _main():
	print("At %s on Amazon ..." %s (ctime()))
	for isbn in ISBNs:
		_show_ranking(isbn)


@register
def _atexit():
	print("All Done at: %s" % (ctime()))

if __name__ == "__main__":
	main()


