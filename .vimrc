"source ~/.vimrc
"PlugInstall

call plug#begin('~/.vim/plugged')

Plug 'vim-airline/vim-airline'
Plug 'vim-airline/vim-airline-themes'
Plug 'scrooloose/nerdtree', { 'on':  'NERDTreeToggle' }
Plug 'morhetz/gruvbox'
Plug 'jiangmiao/auto-pairs'
Plug 'tpope/vim-fugitive'
Plug 'airblade/vim-gitgutte'
Plug 'kien/ctrlp.vim'
Plug 'easymotion/vim-easymotion'
Plug 'scrooloose/syntastic'

"Для scrooloose/syntastic рекомендация
set statusline+=%#warningmsg#
set statusline+=%{SyntasticStatuslineFlag()}
set statusline+=%*

let g:syntastic_always_populate_loc_list = 1
let g:syntastic_auto_loc_list = 1
let g:syntastic_check_on_open = 1
let g:syntastic_check_on_wq = 0





"let g:airline#extensions#tabline#enabled = 1
"let g:airline#extensions#tabline#left_sep = ' '
"let g:airline#extensions#tabline#left_alt_sep = '|'


call plug#end()
map <F4> :NERDTreeToggle<CR>

:set t_Co=256
:syntax on
:let g:mapleader=','
:set number
:colorscheme gruvbox
:set background=dark
:match ErrorMsg /\%>79v.\+/
:syn region Comment start=/\/\*/ end=/\*\//
:set showtabline=2
:set wrap
:set cursorline
:set nocompatible
:set tabstop=2 shiftwidth=2 expandtab
:set hlsearch
:set incsearch

imap <F2> <ESC>:tabn<CR>
map <F2> <ESC>:tabn<CR> 
imap <F3> <ESC>:tabp<CR>
map <F3> <ESC>:tabp<CR> 
map<Leader> <Plug>(easymotion-prefix)


map <silent> <C-h> :call WinMove('h')<CR>
map <silent> <C-j> :call WinMove('j')<CR>
map <silent> <C-k> :call WinMove('k')<CR>
map <silent> <C-l> :call WinMove('l')<CR>

function! WinMove(key)
  let t:curwin = winnr()
  exec "wincmd ".a:key
  if (t:curwin == winnr())
    if(match(a:key,'[jk]'))
      wincmd v
    else
      wincmd s
    endif
    exec "wincmd ".a:key
  endif
endfunction

