import time
import os
import sys
import argparse
import json
import datetime
from nelson.gtomscs import submit

def print_report(results):
    for result in results:
      if 'description' in result:
        print "Description:", result['description']
      if 'traceback' in result:
        print "Traceback:"
        print result['traceback']
      if 'output' in result:
        output = result['output']
        if 'client_returncode' in output:
          print "Client Returncode:", output['client_returncode']
        if 'server_returncode' in output:
          print "Server Returncode:", output['server_returncode']
        if 'server_console' in output:
          print "Server Console:"
          print output['server_console']
        if 'client_console' in output:
          print "Client Console:"
          print output['client_console']

def main():
  parser = argparse.ArgumentParser(description='Submits code to the Udacity site.')
  parser.add_argument('quiz', choices = ['rpc', 'readme'])
  
  args = parser.parse_args()

  path_map = { 'proxy_server': '.', 
               'proxy_cache': '.', 
               'readme': '.'}

  quiz_map = {'rpc': 'pr4_rpc', 'readme': 'pr4_readme' }

  files_map = {
        'pr4_rpc': ['minify_via_rpc.c', 'minifyjpeg.h', 'minifyjpeg_clnt.c', 'minifyjpeg_xdr.c', 
                    'minifyjpeg.c','minifyjpeg.x', 'minifyjpeg_svc.c'],
        'pr4_readme': ['readme-student.md'],
        }

  quiz = quiz_map[args.quiz]

  submit('cs8803-02', quiz, files_map[quiz])

if __name__ == '__main__':
  main()
