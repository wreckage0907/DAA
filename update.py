import os
import json

def getcontent(dir):
    os.chdir(dir)
    folder = [name for name in os.listdir() if os.path.isdir(name)]
    res ={}
    map={"SM":"String Matching ","GREEDY":"Greedy","MSS":"Maximum Subarray Sum","BT":"Backtracking","SORT":"Sorting","DP":"Dynamic Programming"}
    for i in folder:
        os.chdir(i)
        files=[name for name in os.listdir() if os.path.isfile(name)]
        res[map[i]]=files
        os.chdir('..')
    return res

def saver(data, cwd,output_file):
    os.chdir(cwd)
    with open(output_file, 'w') as json_file:
        json.dump(data, json_file, indent=4)
        
cwd = os.getcwd()
codes_dir = os.path.join(cwd, 'CODES')
code = getcontent(codes_dir)


saver(code, cwd,'subtopics.json')