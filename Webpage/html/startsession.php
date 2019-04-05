<!DOCTYPE html>

  
<html>
   <head>
   <meta name="viewport" content="initial-scale=1">
      <title>Session Status</title>
      <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/limonte-sweetalert2/6.11.0/sweetalert2.css"/>
      <script src="https://code.jquery.com/jquery-3.2.1.min.js"></script>
      <script src="https://cdnjs.cloudflare.com/ajax/libs/limonte-sweetalert2/6.11.0/sweetalert2.js"></script>
      <style type="text/css"> 
     body{
       background-image:url('back2.jpg');
       background-size: cover;
       background-attachment: fixed;
     }
     .content{
       background: white;
       width: 50%;
       padding: 30px;
       margin: 100px auto;
       font-family: serif;
       border: solid 10px black;
       border-radius: 25px;
     }
     </style>

   </head>
   <body>

   <center>

   <div class = "content">
   <h1 style = "font-family:serif;font-size:30px;"> Your Session </h1>

   <hr>

   <form  method="post">
   
   <input type="submit" name="button" value="RUN"/>

     </form>
     <br>
     <input type="button" value="exit" onclick="location='login.php'" />
     </div>
     </center>
   </body>
   </html>

  <?php
if (isset($_POST['button'])) {
    if (file_exists('/home/user/Project/status.txt')) {
        $myfile = fopen('/home/user/Project/status.txt', 'r');
        $number=fgets($myfile);
        fclose($myfile);
        if ($number=="1") { //The device is off, then we turn it on.
            $myfile = fopen('/home/user/Project/status.txt', 'w');
            fwrite($myfile, "0");
            fclose($myfile);
          
            echo "<script>
            swal({
              title: 'Are you sure?',
              text: 'You will close the session!',
              type: 'warning',
              showCancelButton: true,
              confirmButtonColor: '#3085d6',
              cancelButtonColor: '#d33',
              confirmButtonText: 'Yes, close it!'
            }).then(function() {
              swal(
                'Session closed!',
                'Your session has been closed',
                'success'
              );
              setTimeout(function () {
                window.location.href = 'startsession.php'; //will redirect to your blog page (an ex: blog.html)
             }, 2000); //will call the function after 2 secs.
            })
          
      </script>";
        } else { // In this case, we would have the device off or an invalid number.
            if ($number=="0") {
                $myfile = fopen('/home/user/Project/status.txt', 'w');
                fwrite($myfile, "1");
                fclose($myfile);
                echo "<script>
            swal({
              title: 'Are you sure?',
              text: 'You will start the session!',
              type: 'warning',
              showCancelButton: true,
              confirmButtonColor: '#3085d6',
              cancelButtonColor: '#d33',
              confirmButtonText: 'Yes, start it!'
            }).then(function() {
              swal(
                'Session started!',
                'Your session has been started',
                'success'
              );
              setTimeout(function () {
                window.location.href = 'startsession.php'; //will redirect to your blog page (an ex: blog.html)
             }, 2000); //will call the function after 2 secs.
            })
          g
      </script>";
            } else {
                $myfile = fopen('/home/user/Project/status.txt', 'w');
                fwrite($myfile, "1");
                fclose($myfile);
                echo "<script>
                swal('Hi there! Say hello to your FreeStress friend!');
                </script>";

                
            }
        }
    } else {
        $fp = fopen('/home/user/Project/status.txt', 'w');
        //To have admin permission, we need to use the umask command
        $old = umask(0);
        file_put_contents("/home/user/Project/status.txt", "0");
        chmod("/home/user/Project/status.txt", 0777);
        umask($old);
        fclose($fp);
    }
}
 ?>
