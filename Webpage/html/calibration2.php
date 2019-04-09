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
     <h1>2nd Calibration</h1>
     <br>
     The second calibration consists of one minute workout, try to do 20 push-ups or squats and then, wait for one minute after you press the button.
     <br>
     <br>
     Exercise for 1 minute, then press the button and we will record your hearth rate average. After 1 minute, your resting heart rate average will be storaged.
     <br>
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
        echo "<script> swal('Good job!', 'Second calibration done', 'success');
        setTimeout(function () {
          window.location.href = 'startsession.php';
       }, 1000); //will call the function after 1 sec.
        </script>";

        $myfile = fopen('/var/www/html/Project/config.txt', 'w');
        fwrite($myfile, "0");
        fclose($myfile);
    } else { // In this case, we would have the device off or an invalid number.
        
    }
}


    
 ?>
