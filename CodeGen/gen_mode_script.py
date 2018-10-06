import os, distutils.dir_util

replacement = "BAT"
typestr = "Mode"
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
