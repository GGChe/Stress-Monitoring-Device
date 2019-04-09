<!DOCTYPE html>

  
<html>
   <head>
      <title>Session</title>
      <meta name="viewport" content="initial-scale=1">
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
   <h1 style = "font-family:serif;font-size:30px;"> Calibration of the device </h1>

   <hr>
     <form method="post">
     <h1>1st Calibration</h1>
     <br>
     The first calibration consists of a resting calibration.
     <br>
     Breathe deeply and relax yourself. Then press the button and we will record your hearth rate average. After 1 minute, your resting heart rate average will be storaged.
     <br>
<input type="submit" name="button" value="Start"/>
     </form>
     <br>
     <br>
     </div>
     </center>
     <script>
                
</script>
   </body>
   </html>
  <?php
if (isset($_POST['button'])) {
  if (file_exists('/var/www/html/Project/config.txt')) {
      $myfile = fopen('/var/www/html/Project/config.txt', 'r');
      $number=fgets($myfile);
      fclose($myfile);
      if ($number=="0") { //The device is off, then we turn it on.
          $myfile = fopen('/var/www/html/Project/config.txt', 'w');
          fwrite($myfile, "1");
          fclose($myfile);

          echo "<script> swal('Please, wait one minute');</script>";
          ob_end_flush();
          flush();
          sleep(3);
          $myfile = fopen('/var/www/html/Project/config.txt', 'w');
          fwrite($myfile, "0");
          fclose($myfile);
          
          echo "<script> swal('Good job!', 'First calibration done', 'success');
          setTimeout(function () {
            window.location.href = 'calibration2.php'; //will redirect to your blog page (an ex: blog.html)
         }, 1000); //will call the function after 2 secs.
          </script>";


          
      } 
  } else {
      $fp = fopen('/home/pi/Project/config.txt', 'w');
      //To have admin permission, we need to use the umask command
      $old = umask(0);
      file_put_contents("/var/www/html/Project/config.txt", "1"); 
      chmod("/var/www/html/Project/config.txt", 0777);
      umask($old);
      fclose($fp);
      echo "<script> swal('Please, wait one minute');</script>";
          ob_end_flush();
          flush();
          sleep(3);
          
          $myfile = fopen('/var/www/html/Project/config.txt', 'w');
          fwrite($myfile, "0");
          fclose($myfile);

          echo "<script> swal('Good job!', 'First calibration done', 'success');
          setTimeout(function () {
            window.location.href = 'calibration2.php'; //will redirect to your blog page (an ex: blog.html)
         }, 1000); //will call the function after 2 secs.
          </script>";

  }
}


    
 ?>
