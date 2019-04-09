<!DOCTYPE html>

  
<html>
   <head>
   <meta name="viewport" content="initial-scale=1">
     <title>Stress Controller Configuration</title>
     <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/limonte-sweetalert2/6.11.0/sweetalert2.css"/>
    <script src="https://code.jquery.com/jquery-3.2.1.min.js"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/limonte-sweetalert2/6.11.0/sweetalert2.js"></script>


     <style type="text/css">
  
     
     body{
       background-image:url('back.jpg');
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
   <h1 style = "font-family:serif;font-size:30px;"> Stress Controller Device Configuration </h1>

   <hr>
     <form method="post">
       Introduce your ID:<br>
       <input type="text" name="IDdata"><br>
       <br>
       <input type="submit" value="Sign up"  />
     </form>
     </div>
    </center>
    <script>
    </script>
   </body>
   </html>
  <?php

  $fp = fopen('/var/www/html/Project/login.txt', 'a');
    if (isset($_POST['IDdata'])) {
      $name=$_POST['IDdata'];
      $name = str_replace(' ', '', $name);
      if($name!=""){
        fwrite($fp, $name."/");
        setcookie("user", $name, time() + (86400), "/"); // 86400 = 1 day
        
        $fp2 = fopen('/var/www/html/Project/user.txt', 'w');
        $old = umask(0);
        file_put_contents("/var/www/html/Project/user.txt", $name);
        chmod("/var/www/html/Project/user.txt", 0777);
        umask($old);
        fclose($fp);
        
        echo "<script> swal('User created', 'You will be redirected to the calibration ', 'success');</script>";
        
        header("refresh:1; url=calibration.php"); //move to the status page
    }else{
      echo "<script> swal('ERROR!', 'Please, enter your new user', 'error');</script>";
      header("refresh:1; url=signup.php"); //move to the status page
    }
    }


    fclose($fp);
 ?>
