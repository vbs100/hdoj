#include <stdio.h>

struct gird {
	int id;
	char num;
	char left;
	short bit;

	char cid;
	char rid;
	char bid;
};

struct section {
	char left;
	short bit;
};

struct col {
	char left;
	short bit;

	struct gird *d[9];
};

struct row {
	char left;
	short bit;

	struct gird *d[9];
};

struct box {
	char left;
	short bit;

	struct gird *d[9];
};

struct sodoku {
	char left;
	struct gird girds[9][9];
	struct row rows[9];
	struct col cols[9];
	struct box boxs[3][3];
};
