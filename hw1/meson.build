project('hw1', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3', 'cpp_std=c++17'])

opencvdep = dependency('opencv4')

executable('hw1',
           'detect_markers.cpp',
           install : true,
           dependencies : opencvdep
           )

run_target('run',
           command : './run.sh')
