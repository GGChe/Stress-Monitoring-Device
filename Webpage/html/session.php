<!DOCTYPE html>

  
<html>
   <head>
   <meta name="viewport" content="initial-scale=1">
      <title>Session</title>
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
   <h1 style = "font-family:serif;font-size:30px;"> Profile </h1>

   <hr>
     <form method="post">
        ID:
        <?php
        echo $_COOKIE["user"];
        setcookie("user", null, -1, '/'); // 86400 = 1 day
        ?>
     </form>
     <br>
     <input type="button" value="Start Session" onclick="location='startsession.php'" />
     <input type="button" value="Recalibrate" onclick="location='calibration.php'" />
     </div>
     </center>
     <script>
                
</script>
   </body>
   </html>
  <?php

   
 ?>