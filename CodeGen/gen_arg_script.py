import os, distutils.dir_util

import sys

numargs = len(sys.argv)
print 'Number of arguments:', numargs , 'arguments.'
print 'Argument List:', str(sys.argv)

if (numargs >=2):
    replacement = sys.argv[1]
    if (numargs >=3):
        typestr = sys.argv[2]
    else:
        typestr = "Debounce"

else:
    replacement = "BUT"
    typestr = "Debounce"


toreplace = "__replace__"
src = "./_replace_"
template = "./_replace_" + typestr + "_template"
dst = "./"+replacement + typestr
distutils.dir_util.copy_tree(template, src)
for dname, dirs, files in os.walk(src):
    for fname in files:
        fpath = os.path.join(dname, fname)
        with open(fpath) as f:
            s = f.read()
        s = s.replace("{$replace}", replacement)
        with open(fpath, "w") as f:
            f.write(s)
        os.rename(fpath, fpath.replace(toreplace, replacement))


os.rename(src,dst)
