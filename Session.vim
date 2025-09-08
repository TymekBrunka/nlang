let SessionLoad = 1
let s:so_save = &g:so | let s:siso_save = &g:siso | setg so=0 siso=0 | setl so=-1 siso=-1
let v:this_session=expand("<sfile>:p")
silent only
silent tabonly
cd ~/Documents/nlang
if expand('%') == '' && !&modified && line('$') <= 1 && getline(1) == ''
  let s:wipebuf = bufnr('%')
endif
let s:shortmess_save = &shortmess
if &shortmess =~ 'A'
  set shortmess=aoOA
else
  set shortmess=aoO
endif
badd +22 ~/Documents/nlang/src/main.c
badd +11 ~/Documents/nlang/CMakeLists.txt
badd +1 ~/Documents/nlang/include/parser/tokenizer.h
badd +1 ~/Documents/nlang/src/parser/tokenizer.c
badd +72 ~/Documents/nlang/include/types.h
badd +74 src/reader.c
badd +25 ~/Documents/nlang/include/reader.h
badd +12 ~/Documents/nlang/include/utils/dyn_arrays.h
badd +2 ~/Documents/nlang/include/reader_internal.h
argglobal
%argdel
tabnew +setlocal\ bufhidden=wipe
tabrewind
edit ~/Documents/nlang/include/reader.h
argglobal
balt ~/Documents/nlang/src/main.c
setlocal foldmethod=manual
setlocal foldexpr=0
setlocal foldmarker={{{,}}}
setlocal foldignore=#
setlocal foldlevel=0
setlocal foldminlines=1
setlocal foldnestmax=20
setlocal foldenable
silent! normal! zE
let &fdl = &fdl
let s:l = 5 - ((4 * winheight(0) + 27) / 55)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 5
normal! 0
tabnext
edit ~/Documents/nlang/CMakeLists.txt
let s:save_splitbelow = &splitbelow
let s:save_splitright = &splitright
set splitbelow splitright
wincmd _ | wincmd |
split
1wincmd k
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
exe '1resize ' . ((&lines * 42 + 29) / 58)
exe '2resize ' . ((&lines * 12 + 29) / 58)
argglobal
balt ~/Documents/nlang/src/main.c
setlocal foldmethod=manual
setlocal foldexpr=0
setlocal foldmarker={{{,}}}
setlocal foldignore=#
setlocal foldlevel=0
setlocal foldminlines=1
setlocal foldnestmax=20
setlocal nofoldenable
silent! normal! zE
let &fdl = &fdl
let s:l = 11 - ((10 * winheight(0) + 21) / 42)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 11
normal! 07|
wincmd w
argglobal
if bufexists(fnamemodify("term://~/Documents/nlang//44607:/usr/bin/zsh;\#toggleterm\#1", ":p")) | buffer term://~/Documents/nlang//44607:/usr/bin/zsh;\#toggleterm\#1 | else | edit term://~/Documents/nlang//44607:/usr/bin/zsh;\#toggleterm\#1 | endif
if &buftype ==# 'terminal'
  silent file term://~/Documents/nlang//44607:/usr/bin/zsh;\#toggleterm\#1
endif
balt ~/Documents/nlang/CMakeLists.txt
setlocal foldmethod=manual
setlocal foldexpr=0
setlocal foldmarker={{{,}}}
setlocal foldignore=#
setlocal foldlevel=0
setlocal foldminlines=1
setlocal foldnestmax=20
setlocal foldenable
let s:l = 2217 - ((11 * winheight(0) + 6) / 12)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 2217
normal! 04|
wincmd w
2wincmd w
exe '1resize ' . ((&lines * 42 + 29) / 58)
exe '2resize ' . ((&lines * 12 + 29) / 58)
tabnext 2
if exists('s:wipebuf') && len(win_findbuf(s:wipebuf)) == 0 && getbufvar(s:wipebuf, '&buftype') isnot# 'terminal'
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
set hlsearch
doautoall SessionLoadPost
unlet SessionLoad
" vim: set ft=vim :
