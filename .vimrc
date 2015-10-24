set nocompatible              " be iMproved
set nu
set noswapfile
syntax on
set backspace=2
set tabstop=4
set shiftwidth=4
set completeopt=menu
set cindent
set rtp+=~/.vim/bundle/vundle/
call vundle#rc()
Bundle 'gmarik/vundle'
"Bundle 'Valloric/YouCompleteMe'  
Bundle 'scrooloose/syntastic'
Bundle 'jiangmiao/auto-pairs'
""""""""""syntastic""""""""""""
let g:syntastic_check_on_open = 1
let g:syntastic_cpp_include_dirs = ['/usr/include/']
let g:syntastic_cpp_remove_include_errors = 1
let g:syntastic_cpp_check_header = 1
let g:syntastic_cpp_compiler = 'clang++'
"set error or warning signs
"let g:syntastic_error_symbol = 'x'
"let g:syntastic_warning_symbol = '!'
""whether to show balloons
let g:syntastic_enable_balloons = 1


""""""""""""YCM""""""""""""""""""""
let g:ycm_global_ycm_extra_conf = '~/.vim/bundle/YouCompleteMe/third_party/ycmd/cpp/ycm/.ycm_extra_conf.py'
let g:ycm_collect_identifiers_from_tags_files = 1
let g:ycm_seed_identifiers_with_syntax = 1
let g:ycm_confirm_extra_conf = 0
filetype plugin indent on
