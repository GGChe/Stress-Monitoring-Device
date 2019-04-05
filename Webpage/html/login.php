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
       ID<br>
       <input type="text" name="IDdata"><br>
       <br>
       <input type="submit" value="Log in"  />
       <br>
       <br>
       <input type="submit" name="signup" value="sign up"  />
     </form>
     </div>
     </center>
     <script>
                
</script>
   </body>
   </html>
  <?php
  if (isset($_POST['IDdata'])) {
      if (file_exists('/home/user/Project/login.txt')) {
        $name=$_POST['IDdata'];
        $name=str_replace(' ', '', $name);
        if (!empty($name)) {
          $filecontent=file_get_contents('/home/user/Project/login.txt');
          $pos=strpos($filecontent,$name);
                  if ($pos===false) {
                    echo "<script> swal('ERROR!', 'Please, Sign up', 'error');</script>";
                  header("refresh:5; url=login.php"); //move to the status page
                  
              } else {
                echo "<script> swal('Logged in', 'You will be redirected to you profile', 'success');</script>";
                  setcookie("user", $name, time() + (86400), "/"); // 86400 = 1 day
                  header("refresh:5; url=session.php"); //move to the status page
                  
              }
            
          }
      }else{
        echo "<script> swal('ERROR', 'Please, Sign up', 'error');</script>";
      }
      
  }

if (isset($_POST['signup'])) {
    if (file_exists('/home/user/Project/login.txt')) {
        echo "<script> swal('Sign up', 'You will be redirected to the sign up page', 'success');</script>";
        header("refresh:2; url=signup.php"); //move to the sign page
    } else {
        echo "<script> swal('Sign up', 'You will be redirected to the sign up page', 'success');</script>";
            
        $fp = fopen('/home/user/Project/login.txt', 'w');
        $old = umask(0);
        file_put_contents("/home/user/Project/login.txt", "/"."admin/");
        chmod("/home/user/Project/login.txt", 0777);
        umask($old);
        fclose($fp);
        header("refresh:2; url=signup.php"); //move to the signup page
    }
}
    
 ?>
