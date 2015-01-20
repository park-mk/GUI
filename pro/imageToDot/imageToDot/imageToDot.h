#ifndef IMAGETODOT_H
#define IMAGETODOT_H

typedef struct _pic_data pic_data;
struct _pic_data
{
		int width, height;				/* �ߴ� */
		int bit_depth;						/* λ�� */
		int flag;								/* һ����־����ʾ�Ƿ���alphaͨ�� */

		unsigned char **rgba;		/* ͼƬ���� */
};

#define PNG_BYTES_TO_CHECK 4
#define HAVE_ALPHA 1
#define NO_ALPHA 0

static int detect_png(const char *filepath, pic_data *out, FILE* outfile);

#endif