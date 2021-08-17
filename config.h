/* See LICENSE file for copyright and license details.*/

#ifndef CONFIG_H
#define CONFIG_H

/* colors                      fg,  bg */
static const Cpair cdir    = { 31, 0 };
static const Cpair cfile   = { 243, 0 };
static const Cpair clnk    = { 96, 0 };
static const Cpair cblk    = { 95, 0 };
static const Cpair cchr    = { 94, 0 };
static const Cpair cifo    = { 93, 0 };
static const Cpair csock   = { 92, 0 };
static const Cpair cexec   = { 91, 0 };
static const Cpair cother  = { 90, 0 };

static const Cpair cframe  = { 233, 233 };
static const Cpair cpanell = { 166, 233 };
static const Cpair cpanelr = { 5,   233 };
static const Cpair cerr    = { 124, 0 };
static const Cpair cprompt = { 33,  0 };
static const Cpair csearch = { 255, 0 };
static const Cpair cstatus = { 243, 0 };

/* commands */
static const char *rm_cmd[] = { "rm", "-rf" }; /* delete */
static const char *cp_cmd[] = { "cp", "-r" }; /* copy */
static const char *mv_cmd[] = { "mv" }; /* move */
static const char delconf[] = "yes";

static const size_t rm_cmd_len  = LEN(rm_cmd);
static const size_t cp_cmd_len  = LEN(cp_cmd);
static const size_t mv_cmd_len  = LEN(mv_cmd);
static const size_t delconf_len = LEN(delconf);

/* bookmarks */
static const char root[]   = "/";

/* software */
static const char *videoplayer[]                    = { "mpv" };
static const char *audioplayer[]                    = { "mpv" };
static const char *imageviewer[]                   = { "sxiv" };
static const char *browser[]                      = { "links" };
static const char *bookreader[]                 = { "zathura" };
static const char *nesemu[]                       = { "mesen" };
static const char *snesemu[]                      = { "bsnes" };
static const char *usereditor[]                     = { "vis" };

/* extensions*/
static const char *image[]                   = { "jpg", "png" };
static const char *web[]                    = { "htm", "html" };
static const char *book[     = { "epub", "pdf", "cbz", "djvu" };
static const char *video[]            = { "m4v", "mkv", "mp4" };
static const char *audio[]                   = { "mp3", "flac"};
static const char *nes[]                            = { "nes" };
static const char *snes[]                           = { "sfc" };

static Rule rules[] = {
	{video,     LEN(video),     videoplayer, LEN(videoplayer) },
	{audio,     LEN(audio),     audioplayer, LEN(audioplayer) },
	{image,     LEN(image),     imageviewer, LEN(imageviewer) },
	{web,       LEN(web),       browser,     LEN(browser)     },
	{book,      LEN(book),      bookreader,  LEN(bookreader)  },
	{nes,       LEN(nes),       nesemu,      LEN(nesemu)      },
	{snes,      LEN(snes),      snesemu,     LEN(snesemu)     },
};

/* normal keys */
static Key nkeys[] = {
	/* keyval                      function      arg */
	{ {.ch = 'j'},                 mv_ver,       {.i = -1}       },
	{ {.ch = 'k'},                 mv_ver,       {.i = +1}       },
	{ {.key = TB_KEY_CTRL_U},      mv_ver,       {.i = +3}       },
	{ {.key = TB_KEY_CTRL_D},      mv_ver,       {.i = -3}       },
	{ {.key = TB_KEY_PGUP },       mv_ver,       {.i = +10}      },
	{ {.key = TB_KEY_PGDN },       mv_ver,       {.i = -10}      },
	{ {.key = TB_KEY_ENTER},       mvfwd,        {.i = 0}        },
	{ {.ch = 'l'},                 mvfwd,        {.i = 0}        },
	{ {.ch = 'h'},                 mvbk,         {.i = 0}        },
	{ {.ch = 'g'},                 mvtop,        {.i = 0}        },
	{ {.ch = 'G'},                 mvbtm,        {.i = 0}        },
	{ {.ch = 'n'},                 crnf,         {0}             },
	{ {.ch = 'N'},                 crnd,         {0}             },
	{ {.ch = 'd'},                 delent,       {0}             },
	{ {.ch = 'x'},                 calcdir,      {0}             },
	{ {.ch = '/'},                 start_filter, {0}             },
	{ {.ch = 'q'},                 quit,         {0}             },
	{ {.ch = 'v'},                 start_vmode,  {0}             },
	{ {.ch = 'y'},                 yank,         {0}             },
	{ {.ch = 'p'},                 paste,        {0}             },
	{ {.ch = 'P'},                 selmv,        {0}             },
	{ {.ch = 'c'},                 rname,        {0}             },
	{ {.key = TB_KEY_SPACE},       switch_pane,  {0}             },
	{ {.ch = '\\'},                bkmrk,        {.v = root}     },
	{ {.ch = '.'},                 toggle_df,    {0}             },
};

/* visual keys */
static Key vkeys[] = {
	/* keyval                      function         arg */
	{ {.ch = 'j'},                 seldwn,          {.i = -1}      },
	{ {.ch = 'k'},                 selup,           {.i = +1}      },
	{ {.ch = 'a'},                 selall,          {0}            },
	{ {.ch = 'y'},                 selynk,          {0}            },
	{ {.ch = 'd'},                 seldel,          {.v = delconf} },
	{ {.ch = 'q'},                 exit_vmode,      {0}            },
	{ {.ch = 'v'},                 exit_vmode,      {0}            },
	{ {.key = TB_KEY_ESC},         exit_vmode,      {0}            },
};

static const size_t nkeyslen = LEN(nkeys);
static const size_t vkeyslen = LEN(vkeys);

/* permissions */
static const mode_t ndir_perm = S_IRWXU;
static const mode_t nf_perm   = S_IRUSR | S_IWUSR;

/* dotfiles */
static int show_dotfiles = 1;

/* statusbar */
static const char dtfmt[] = "%F %R"; /* date time format */

/* unicode chars */
#define u_hl  0x2500 /* ─ */
#define u_vl  0x2502 /* │ */
#define u_cnw 0x250C /* ┌ */
#define u_cne 0x2510 /* ┐ */
#define u_csw 0x2514 /* └ */
#define u_cse 0x2518 /* ┘ */
#define u_mn  0x252C /* ┬ */
#define u_ms  0x2534 /* ┴ */

#endif /* CONFIG_H */
