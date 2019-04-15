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
     The first calibration will record your heart rate at rest.
     <br>
     Breath and relax. Press the button and we will record your heart rate. After 1 minute, your heart rate average at rest will be stored. 
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
    /**
     * This code is in charge of the waiting time for the calibration of the system. 
     * Thus, the code is prepared to wait during 60 + 4 seconds (2 up and 2 down) that let the sensor the enough time for the calculations required.
     */
    if (isset($_POST['button'])) {
      if (file_exists('/var/www/html/Project/config.txt')) {
        $myfile = fopen('/var/www/html/Project/config.txt', 'r');
        $number=fgets($myfile);
        fclose($myfile);
          if ($number=="0") { //The device is off, then we turn it on.
            // write a "1"
            $myfile = fopen('/var/www/html/Project/config.txt', 'w');
            fwrite($myfile, "1");
            fclose($myfile);
            echo "<script> swal('Please, wait for one minute');</script>";
            //wait(5000);
            ob_flush();
            flush();
            sleep(40);
            //wait(5000);
            // Come back to "0"
            $myfile = fopen('/var/www/html/Project/config.txt', 'w');
            fwrite($myfile, "0");
            fclose($myfile);
          
            echo "<script> swal('Good job!', 'First calibration is done', 'success');
               setTimeout(function () {
               window.location.href = 'calibration2.php'; //will redirect to your blog page (an ex: blog.html)
                }, 1000); //will call the function after 2 secs.
                </script>";
            } 
      } else {
        $fp = fopen('/home/pi/Project/config.txt', 'w');
        $old = umask(0);
        file_put_contents("/var/www/html/Project/config.txt", "1"); 
        chmod("/var/www/html/Project/config.txt", 0777);
        umask($old);
        fclose($fp);
        echo "<script> swal('Please, wait for one minute');</script>";
        //wait(5000);
        ob_flush();
        flush();
            sleep(40);
            //wait(5000);    
        $myfile = fopen('/var/www/html/Project/config.txt', 'w');
        fwrite($myfile, "0");
        fclose($myfile);
        echo "<script> swal('Good job!', 'First calibration is done', 'success');
            setTimeout(function () {
            window.location.href = 'calibration2.php'; //will redirect to your blog page (an ex: blog.html)
            }, 1000); //will call the function after 2 secs.
            </script>";
  }
}


    
 ?>
