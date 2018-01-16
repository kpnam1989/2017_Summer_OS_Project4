# Project description
This is my second class at OMSCS. The first class is Compiler: Theory and Practice. This is another challenging class for me due to my lack of training in Computer Science. 

Through the class, I was able to learn extensively about:
-	The C programming language
-	Memory allocation in an operating system
-	Communications between processes in an OS
-	Remote procedure call

I am proud to have overcome my disadvantages, and to be able to perform well in this class. Indeed, there were many times I realized that I was able to understand the materials and the logic much better than other students in the class with a Computer Science background.

# Solution: Write up for Pr 4
## Project design
I only finish the single threaded version of the project and I think that it has a very simple design. Most of the design decision has been made by requiring that students only need to implement the function to get the client handler and minify_via_rpc. 

...[removed because this contains some solutions]...

If I started the project with good understanding of the flag -M, where I can access the status variable without having to modify the code in minifyjpeg_clnt.c, I would have written the solution differently. 

## Notes 
### Struggle with the project
I think many students have issue with running the code locally. My solution is to run rpcinfo first and then run the server. If (after rebooting the machine) I run the server first, I will always have an error. 

My struggle with the project 4 is that I did not understand the requirements. After reading the project description, I was under the impression that I need to find a way to call the rpc function once and the function is able to handle files of arbitrarily large size. I then coded up some simple ways to transfer a file chunk by chunk between clients and servers based on this thread:

https://stackoverflow.com/questions/2082033/sun-rpc-transferring-binary-files

I felt that my approach was overly complicated because I would need to save a temporary file on the server, create a temporary resized image on the server, then transfer it to the client into another temporary file. The client would then have to open it and pass it into function minify_via_rpc. The whole process has a lot of redundancy. 

I was not sure if this was the right approach, so I spent a few days worrying and researching for a function to transfer the file of arbitrarge large file between clients and servers. It was only after I talked with Tony that I realized that my approach was an overkill: using one buffer large enough to pass Bonnie tests should suffice. With the knowledge that I could use opaque data, I was able to pass Bonnie tests fairly quickly.

### The compiling flag -MN
Another issue with the project is the flag -MN. The flat -M is not necessary for the basic part of the project and complicates the work. When I started with the flag -MN, my server kept timing out. I was lucky to know that there are other flags that I could use. Indeed, my first experience with RPC involved using the flag -C. Once I was familiar with the RPC call, I started with -N, and then -MN. 

My experience having a function pair of server/client with the -C flag helps me greatly in understand the -MN flag. 

Finally, even though I was not able to implement the multi-threaded extra credit, I still learned a lot about the implementation of RPC by comparing the templates generated by using the flag -C, -N and -MN. 

### Magik minify
There seems to be some redundancy in the magikminify_test file. 
src = ImageToBlob(&image_info, image, &len, exception);
dst = magickminify(src, src_len, &dst_len);
resize = BlobToImage(&image_info, dst, dst_len, exception);
So magicminify takes a Blob and returns a Blob. But the process of magicminify is:
	image = BlobToImage(&image_info, src, src_len, exception);
	resize = MinifyImage(image, exception);
	ans = ImageToBlob(&image_info, resize, &len, exception);
Magicminify turns this input Blob into an image, resizes it, and returns a Blob. I think we can write the codes in another way that requires less transferring between Image and Blob.

## Reference

Transferring large files via RPC
https://stackoverflow.com/questions/2082033/sun-rpc-transferring-binary-files

Good introduction to RPC
https://www.cs.rutgers.edu/~pxk/rutgers/notes/content/ra-sunrpc.pdf

