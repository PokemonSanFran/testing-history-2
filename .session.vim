let SessionLoad = 1
if &cp | set nocp | endif
let s:so_save = &g:so | let s:siso_save = &g:siso | setg so=0 siso=0 | setl so=-1 siso=-1
let v:this_session=expand("<sfile>:p")
silent only
silent tabonly
cd ~/Decomps/pkmnsnfrn
if expand('%') == '' && !&modified && line('$') <= 1 && getline(1) == ''
  let s:wipebuf = bufnr('%')
endif
let s:shortmess_save = &shortmess
if &shortmess =~ 'A'
  set shortmess=aoOA
else
  set shortmess=aoO
endif
badd +1 new
badd +1 vertical\ new
badd +1 include/constants/vars.h
badd +1 include/constants/vars_define.h
badd +1 data/scripts/movement.inc
badd +1 include/constants/items.h
badd +4 include/constants/opponents.h
badd +1 include/constants/flags.h
badd +537 asm/macros/event.inc
badd +1 asm/macros/movement.inc
badd +1 include/constants/species.h
badd +199 ~/.zshrc
badd +1 ~/.vim/vimrc
badd +1 data/quests/bluerobbery.pory
badd +2 data/maps/Chinatown_Tunnel/scripts.pory
badd +213 ~/Downloads/FirefoxDev.itermcolors
badd +1 data/battle_anim_scripts.s
badd +38 src/quest_strings.c
badd +1 src/quests.c
argglobal
%argdel
$argadd ~/.vim/vimrc
set stal=2
tabnew +setlocal\ bufhidden=wipe
tabrewind
edit asm/macros/event.inc
let s:save_splitbelow = &splitbelow
let s:save_splitright = &splitright
set splitbelow splitright
wincmd _ | wincmd |
vsplit
wincmd _ | wincmd |
vsplit
2wincmd h
wincmd w
wincmd w
wincmd _ | wincmd |
split
wincmd _ | wincmd |
split
2wincmd k
wincmd w
wincmd w
let &splitbelow = s:save_splitbelow
let &splitright = s:save_splitright
wincmd t
let s:save_winminheight = &winminheight
let s:save_winminwidth = &winminwidth
set winminheight=0
set winheight=1
set winminwidth=0
set winwidth=1
exe 'vert 1resize ' . ((&columns * 79 + 119) / 238)
exe 'vert 2resize ' . ((&columns * 78 + 119) / 238)
exe '3resize ' . ((&lines * 20 + 32) / 64)
exe 'vert 3resize ' . ((&columns * 79 + 119) / 238)
exe '4resize ' . ((&lines * 20 + 32) / 64)
exe 'vert 4resize ' . ((&columns * 79 + 119) / 238)
exe '5resize ' . ((&lines * 19 + 32) / 64)
exe 'vert 5resize ' . ((&columns * 79 + 119) / 238)
argglobal
terminal ++curwin ++cols=79 ++rows=61 
let s:term_buf_21 = bufnr()
balt new
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
let s:l = 1 - ((0 * winheight(0) + 30) / 61)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 1
normal! 0
wincmd w
argglobal
balt ~/.zshrc
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let &fdl = &fdl
let s:l = 537 - ((44 * winheight(0) + 30) / 61)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 537
normal! 0124|
wincmd w
argglobal
if bufexists(fnamemodify("~/.vim/vimrc", ":p")) | buffer ~/.vim/vimrc | else | edit ~/.vim/vimrc | endif
balt ~/.zshrc
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let &fdl = &fdl
let s:l = 76 - ((16 * winheight(0) + 10) / 20)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 76
normal! 0
wincmd w
argglobal
if bufexists(fnamemodify("src/quests.c", ":p")) | buffer src/quests.c | else | edit src/quests.c | endif
balt ~/.zshrc
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let &fdl = &fdl
let s:l = 21 - ((5 * winheight(0) + 10) / 20)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 21
normal! $
wincmd w
argglobal
if bufexists(fnamemodify("src/quest_strings.c", ":p")) | buffer src/quest_strings.c | else | edit src/quest_strings.c | endif
balt data/battle_anim_scripts.s
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let &fdl = &fdl
let s:l = 38 - ((5 * winheight(0) + 9) / 19)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 38
normal! 052|
wincmd w
2wincmd w
exe 'vert 1resize ' . ((&columns * 79 + 119) / 238)
exe 'vert 2resize ' . ((&columns * 78 + 119) / 238)
exe '3resize ' . ((&lines * 20 + 32) / 64)
exe 'vert 3resize ' . ((&columns * 79 + 119) / 238)
exe '4resize ' . ((&lines * 20 + 32) / 64)
exe 'vert 4resize ' . ((&columns * 79 + 119) / 238)
exe '5resize ' . ((&lines * 19 + 32) / 64)
exe 'vert 5resize ' . ((&columns * 79 + 119) / 238)
tabnext
edit include/constants/flags.h
let s:save_splitbelow = &splitbelow
let s:save_splitright = &splitright
set splitbelow splitright
wincmd _ | wincmd |
split
1wincmd k
wincmd _ | wincmd |
vsplit
wincmd _ | wincmd |
vsplit
wincmd _ | wincmd |
vsplit
3wincmd h
wincmd w
wincmd w
wincmd w
wincmd w
wincmd _ | wincmd |
vsplit
wincmd _ | wincmd |
vsplit
wincmd _ | wincmd |
vsplit
3wincmd h
wincmd w
wincmd w
wincmd w
let &splitbelow = s:save_splitbelow
let &splitright = s:save_splitright
wincmd t
let s:save_winminheight = &winminheight
let s:save_winminwidth = &winminwidth
set winminheight=0
set winheight=1
set winminwidth=0
set winwidth=1
exe '1resize ' . ((&lines * 30 + 32) / 64)
exe 'vert 1resize ' . ((&columns * 59 + 119) / 238)
exe '2resize ' . ((&lines * 30 + 32) / 64)
exe 'vert 2resize ' . ((&columns * 59 + 119) / 238)
exe '3resize ' . ((&lines * 30 + 32) / 64)
exe 'vert 3resize ' . ((&columns * 59 + 119) / 238)
exe '4resize ' . ((&lines * 30 + 32) / 64)
exe 'vert 4resize ' . ((&columns * 58 + 119) / 238)
exe '5resize ' . ((&lines * 30 + 32) / 64)
exe 'vert 5resize ' . ((&columns * 59 + 119) / 238)
exe '6resize ' . ((&lines * 30 + 32) / 64)
exe 'vert 6resize ' . ((&columns * 59 + 119) / 238)
exe '7resize ' . ((&lines * 30 + 32) / 64)
exe 'vert 7resize ' . ((&columns * 59 + 119) / 238)
exe '8resize ' . ((&lines * 30 + 32) / 64)
exe 'vert 8resize ' . ((&columns * 58 + 119) / 238)
argglobal
balt include/constants/species.h
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let &fdl = &fdl
let s:l = 1 - ((0 * winheight(0) + 15) / 30)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 1
normal! 0
wincmd w
argglobal
if bufexists(fnamemodify("include/constants/species.h", ":p")) | buffer include/constants/species.h | else | edit include/constants/species.h | endif
balt include/constants/flags.h
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let &fdl = &fdl
let s:l = 1 - ((0 * winheight(0) + 15) / 30)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 1
normal! 0
wincmd w
argglobal
if bufexists(fnamemodify("asm/macros/movement.inc", ":p")) | buffer asm/macros/movement.inc | else | edit asm/macros/movement.inc | endif
balt include/constants/species.h
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let &fdl = &fdl
let s:l = 1 - ((0 * winheight(0) + 15) / 30)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 1
normal! 09|
wincmd w
argglobal
if bufexists(fnamemodify("include/constants/vars_define.h", ":p")) | buffer include/constants/vars_define.h | else | edit include/constants/vars_define.h | endif
balt asm/macros/movement.inc
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let &fdl = &fdl
let s:l = 1 - ((0 * winheight(0) + 15) / 30)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 1
normal! 0
wincmd w
argglobal
if bufexists(fnamemodify("include/constants/opponents.h", ":p")) | buffer include/constants/opponents.h | else | edit include/constants/opponents.h | endif
balt include/constants/flags.h
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let &fdl = &fdl
let s:l = 4 - ((3 * winheight(0) + 15) / 30)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 4
normal! 0
wincmd w
argglobal
if bufexists(fnamemodify("include/constants/flags.h", ":p")) | buffer include/constants/flags.h | else | edit include/constants/flags.h | endif
balt include/constants/opponents.h
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let &fdl = &fdl
let s:l = 1 - ((0 * winheight(0) + 15) / 30)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 1
normal! 0
wincmd w
argglobal
if bufexists(fnamemodify("data/scripts/movement.inc", ":p")) | buffer data/scripts/movement.inc | else | edit data/scripts/movement.inc | endif
balt include/constants/flags.h
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let &fdl = &fdl
let s:l = 1 - ((0 * winheight(0) + 15) / 30)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 1
normal! 0
wincmd w
argglobal
if bufexists(fnamemodify("include/constants/vars.h", ":p")) | buffer include/constants/vars.h | else | edit include/constants/vars.h | endif
balt data/scripts/movement.inc
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let &fdl = &fdl
let s:l = 1 - ((0 * winheight(0) + 15) / 30)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 1
normal! 0
wincmd w
exe '1resize ' . ((&lines * 30 + 32) / 64)
exe 'vert 1resize ' . ((&columns * 59 + 119) / 238)
exe '2resize ' . ((&lines * 30 + 32) / 64)
exe 'vert 2resize ' . ((&columns * 59 + 119) / 238)
exe '3resize ' . ((&lines * 30 + 32) / 64)
exe 'vert 3resize ' . ((&columns * 59 + 119) / 238)
exe '4resize ' . ((&lines * 30 + 32) / 64)
exe 'vert 4resize ' . ((&columns * 58 + 119) / 238)
exe '5resize ' . ((&lines * 30 + 32) / 64)
exe 'vert 5resize ' . ((&columns * 59 + 119) / 238)
exe '6resize ' . ((&lines * 30 + 32) / 64)
exe 'vert 6resize ' . ((&columns * 59 + 119) / 238)
exe '7resize ' . ((&lines * 30 + 32) / 64)
exe 'vert 7resize ' . ((&columns * 59 + 119) / 238)
exe '8resize ' . ((&lines * 30 + 32) / 64)
exe 'vert 8resize ' . ((&columns * 58 + 119) / 238)
tabnext 1
set stal=1
if exists('s:wipebuf') && len(win_findbuf(s:wipebuf)) == 0
  silent exe 'bwipe ' . s:wipebuf
endif
unlet! s:wipebuf
set winheight=1 winwidth=20
let &shortmess = s:shortmess_save
let &winminheight = s:save_winminheight
let &winminwidth = s:save_winminwidth
let s:sx = expand("<sfile>:p:r")."x.vim"
if filereadable(s:sx)
  exe "source " . fnameescape(s:sx)
endif
let &g:so = s:so_save | let &g:siso = s:siso_save
nohlsearch
doautoall SessionLoadPost
unlet SessionLoad
" vim: set ft=vim :
