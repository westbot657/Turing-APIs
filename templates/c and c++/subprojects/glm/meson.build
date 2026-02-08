project('glm', ['cpp'], 
        #  version         : '0.9.9.8',  
         license         : ['MIT', 'HBL'],
         meson_version   : '>= 0.49.0')




glm_dep = declare_dependency(
  include_directories: include_directories('include')
)




install_subdir('include/glm', 
                exclude_files: ['CMakeLists.txt'], 
                install_dir : 'include')

install_data(['COPYING.txt'],
               rename      : ['LICENSE'],
               install_dir :  'share/licenses/glm')

if get_option('install_docs')
    install_subdir('doc/api', install_dir : 'share/docs/glm')
    install_data(['doc/manual.pdf'], install_dir :  'share/docs/glm')
endif