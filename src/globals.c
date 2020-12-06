/* File: globals.c
 *
 * This file is part of XSCHEM,
 * a schematic capture and Spice/Vhdl/Verilog netlisting tool for circuit
 * simulation.
 * Copyright (C) 1998-2020 Stefan Frederik Schippers
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#include "xschem.h"


/* X11 specific globals */
Colormap colormap;
Window pre_window; /* preview when opening files */
Window parent_of_topwindow;
unsigned char **pixdata;
unsigned char pixdata_init[22][32]={    /* fill patterns... indexed by laynumb. */
{0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff, 0xff,/*0 */
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff},
{0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff, 0xff,/*1 */
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},/*2 */
{/*3 */
   0x55, 0x55, 0x00, 0x00, 0xaa, 0xaa, 0x00, 0x00, 0x55, 0x55, 0x00, 0x00, 0xaa, 0xaa, 0x00, 0x00,
   0x55, 0x55, 0x00, 0x00, 0xaa, 0xaa, 0x00, 0x00, 0x55, 0x55, 0x00, 0x00, 0xaa, 0xaa, 0x00, 0x00
},
{0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff, 0xff,/*4 */
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff},
{0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff, 0xff,/*5 */
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff},
{/*6 */
   0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x10, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x10, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
},
{/*7 */
   0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02
},
{/*8 */
   0x11, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x11, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x11, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x11, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
},
{/*9 */
   0x04, 0x41, 0x00, 0x00, 0x10, 0x04, 0x00, 0x00, 0x41, 0x10, 0x00, 0x00,
   0x04, 0x41, 0x00, 0x00, 0x10, 0x04, 0x00, 0x00, 0x41, 0x10, 0x00, 0x00,
   0x04, 0x41, 0x00, 0x00, 0x10, 0x04, 0x00, 0x00
},
{0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff, 0xff,/*10 */
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff},
{/*11 */
   0x11, 0x11, 0x00, 0x00, 0x44, 0x44, 0x00, 0x00, 0x11, 0x11, 0x00, 0x00,
   0x44, 0x44, 0x00, 0x00, 0x11, 0x11, 0x00, 0x00, 0x44, 0x44, 0x00, 0x00,
   0x11, 0x11, 0x00, 0x00, 0x44, 0x44, 0x00, 0x00
},
{/*12 */
   0x04, 0x04, 0x02, 0x02, 0x01, 0x01, 0x80, 0x80, 0x40, 0x40, 0x20, 0x20,
   0x10, 0x10, 0x08, 0x08, 0x04, 0x04, 0x02, 0x02, 0x01, 0x01, 0x80, 0x80,
   0x40, 0x40, 0x20, 0x20, 0x10, 0x10, 0x08, 0x08
},
{/*13 */
   0x11, 0x11, 0x22, 0x22, 0x44, 0x44, 0x88, 0x88, 0x11, 0x11, 0x22, 0x22, 0x44, 0x44, 0x88, 0x88,
   0x11, 0x11, 0x22, 0x22, 0x44, 0x44, 0x88, 0x88, 0x11, 0x11, 0x22, 0x22, 0x44, 0x44, 0x88, 0x88
},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},/*14 */
{/*15 */
   0x44, 0x44, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x44, 0x44, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x44, 0x44, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x44, 0x44, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
},
{  0x11, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x22, 0x22, 0x00, 0x00,/*16 */
   0x00, 0x00, 0x00, 0x00, 0x44, 0x44, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x88, 0x88, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},/*17 */
{0x55,0x55,0xaa,0xaa,0x55,0x55,0xaa,0xaa,0x55,0x55,0xaa,0xaa,0x55,0x55,0xaa,0xaa,/*18 */
 0x55,0x55,0xaa,0xaa,0x55,0x55,0xaa,0xaa,0x55,0x55,0xaa,0xaa,0x55,0x55,0xaa,0xaa},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},/*19 */
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},/*20 */
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}/*21 */
};
GC *gcstipple,*gc;
Pixmap *pixmap = NULL;
Display *display;
Pixmap cad_icon_pixmap=0, cad_icon_mask=0;
XPoint *gridpoint;         /* pointer to array of gridpoints, used in draw() */
XColor xcolor_array[256];
Visual *visual;
#ifdef HAS_CAIRO
XRenderPictFormat *render_format;

#if HAS_XCB==1
xcb_connection_t *xcbconn;
xcb_render_pictforminfo_t format_rgb, format_rgba;
xcb_screen_t *screen_xcb;
xcb_visualtype_t *visual_xcb;
#endif /*HAS_XCB */
#endif /*HAS_CAIRO */

/* these variables are mirrored in tcl code */
int fullscreen=0;
char *netlist_dir=NULL; /* user set netlist directory via cmd-option or menu or xschemrc */
int top_subckt = 0;
int spiceprefix = 1;
int unzoom_nodrift=1;
int change_lw=0; /* allow change lw */
int incr_hilight=1;
unsigned short enable_stretch=0;
int auto_hilight=0;
int a3page=-1;
int has_x=1;
int split_files=0; /* split netlist files 20081202 */
double cadgrid = CADGRID;
double cadsnap = CADSNAP;
int draw_grid=1;
int rainbow_colors=0;
int dis_uniq_names=0; /* if set allow instances with duplicate names */
int persistent_command=0; /* remember last command 20181022 */
int color_ps=-1;
int only_probes=0;
int netlist_show=0;
int flat_netlist=0;
int cadlayers=0;
int hide_symbols = 0; /* draw only a bounding box for component instances and @symname, @name texts */
int dark_colorscheme=1;
char cairo_font_name[1024]="Sans Serif";
char svg_font_name[1024]="Sans Serif";
double cairo_font_scale=1.0; /* default: 1.0, allows to adjust font size */
double nocairo_font_xscale=0.85; /* match with cairo sizing */
double nocairo_font_yscale=0.88; /* match with cairo sizing */
double cairo_font_line_spacing=1.0; /* allows to change line spacing: default: 1.0 */
/* lift up the text by 'n' pixels (zoom corrected) within the bbox.  */
/* This correction is used to better align existing schematics */
/* compared to the nocairo xschem version. */
/* allowed values should be in the range [-4, 4] */
double cairo_vert_correct=0.0;
double nocairo_vert_correct=0.0;
int sym_txt=1;
int netlist_type=-1;
int show_pin_net_names = 0;



int help=0; /* help option set to global scope, printing help is deferred */
            /* when configuration ~/.schem has been read 20140406 */
int no_draw=0;
int manhattan_lines=0;
FILE *errfp;
char *filename=NULL; /* filename given on cmdline */
char user_conf_dir[PATH_MAX];
char home_dir[PATH_MAX]; /* home dir obtained via getpwuid */
char pwd_dir[PATH_MAX];  /* obtained via getcwd() */
#ifndef __unix__
char win_temp_dir[PATH_MAX]="";
const char fopen_read_mode[] = "rb";
#else
const char fopen_read_mode[] = "r";
#endif
int load_initfile=1;
char plotfile[PATH_MAX] = {'\0'};
char rcfile[PATH_MAX] = {'\0'};
char *tcl_command = NULL;
char tcl_script[PATH_MAX] = {'\0'};
int quit=0;  /* set from process_options (ex netlist from cmdline and quit) */
int debug_var=-10;  /* will be set to 0 in xinit.c */
int tcp_port = 0;
int do_print=0;
int no_readline=0;
int fill=1; /* filled rectangles */
int draw_pixmap=1; /* use pixmap for double buffer */
int draw_window=0;
int text_svg=1; /* use <text> svg element for text instead of xschem's internal vector font */
double cadhalfdotsize = CADHALFDOTSIZE;
unsigned int color_index[256]; /* layer color lookup table */
int max_undo=MAX_UNDO;
int draw_dots=1;
int draw_single_layer=-1;
int yyparse_error = 0;
int *enable_layer;
int n_active_layers=0;
int *active_layer;
int depth;
int *fill_type; /*20171117 for every layer: 0: no fill, 1, solid fill, 2: stipple fill */
char **color_array;
char *xschem_executable=NULL;
double *character[256]; /* array or per-char coordinates of xschem internal vector font */
Tcl_Interp *interp;
int do_netlist=0;  /* set by process_options if user wants netllist from cmdline */
int do_simulation=0;
int do_waves=0;
int netlist_count=0; /* netlist counter incremented at any cell being netlisted */
char hiersep[20]=".";
char bus_char[3] = {0, 0, 0};
int horizontal_move=0;
int vertical_move=0;
int pending_fullzoom=0;
double color_dim=0.0;
int no_undo=0;
int enable_drill=0; /* 20171211 pass net hilights through components with 'propagate_to' property set on pins */
size_t get_tok_value_size;
size_t get_tok_size;
int batch_mode = 0; /* no tcl console if set; batch mode */
int cairo_longest_line;
int cairo_lines;
int show_erc=1;

/* following data is relative to the current schematic */
Xschem_ctx *xctx;
