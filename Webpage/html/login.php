/**
 *
 * "Webpage Architecture for the Stress_Controller_Device Project"
 * University of Glasgow
 * Supervised by: Bernd Porr
 * By Ahmed Elmogamer, Daewon Jung and Gabriel Galeote Checa
 *
 * This introduction is valid for all the webpage codes provided for the webpage architecture proposed.
 *
 * Official project location:
 * https://github.com/GGChe/Stress_Controller_Device
 *
 * -----------------------------------------------------------------
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 **/



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
       background-image:url('mainback.jpg');
       background-size: cover;
       background-repeat:no-repeat;
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
    /**
     * The login page consists of two sections: 
     *      1) Check if the user exists and login.
     *      2) Move to sign up webpage for creating a new user.
     * 
     * We also need to initialise all the files in order to avoid any kind of uncoherence.
     */

     // Create some files and initialise it.
    $fpstatus = fopen('/var/www/html/Project/status.txt', 'w');
    file_put_contents("/var/www/html/Project/status.txt", "0");
    fclose($fpstatus);
    $fpexit = fopen('/var/www/html/Project/exit.txt', 'w');
    file_put_contents("/var/www/html/Project/exit.txt", "0");
    fclose($fpexit);
   
    /**
     * To check if the users already exists on the "users.txt" we need to read all the users file and check whether the user
     * exists in the file or we need to create a new user.
     */
    if (isset($_POST['IDdata'])) {
      if (file_exists('/var/www/html/Project/users.txt')) {
        $name=$_POST['IDdata'];
        $name=str_replace(' ', '', $name);
        if (!empty($name)) {
          $filecontent=file_get_contents('/var/www/html/Project/users.txt');
          $pos=strpos($filecontent,$name);
            if ($pos===false) {
              echo "<script> swal('ERROR!', 'Please, Sign up', 'error');</script>";
              header("refresh:2; url=login.php"); // move to login page again to re-login again.
            } else {
              // If we enter here, the user already exists on the "users.txt" file and then, we write this user on the "username.txt". 
              echo "<script> swal('Logged in', 'You will be redirected to you profile', 'success');</script>";
              setcookie("user", $name, time() + (86400), "/"); // we create a cookie that is pretty useful for interaction between the differente pages.
              $fp = fopen('/var/www/html/Project/status.txt', 'w');
              file_put_contents("/var/www/html/Project/status.txt", "1"); 
              fclose($fp);
              $fp = fopen('/var/www/html/Project/username.txt', 'w');
              file_put_contents("/var/www/html/Project/username.txt", $name); 
              fclose($fp);
              header("refresh:2; url=session.php"); 
              }
          }
      }else{
        echo "<script> swal('ERROR', 'Please, Sign up', 'error');</script>";
        header("refresh:2; url=login.php"); //move to the status page
      }
  }

  /**
   * If we press the sign up button, then we move to the sign up webpage where we will create a new user on the "users.txt" file. 
   * We need to check if it is the first time that we sign up. If this is the case, we must create the new folder and files. 
   */
  if (isset($_POST['signup'])) {
    if (file_exists('/var/www/html/Project/users.txt')) { // if the file exists, we can directly move to the signup file.
        echo "<script> swal('Sign up', 'You will be redirected to the sign up page', 'success');</script>";
        $fp = fopen('/var/www/html/Project/status.txt', 'w');
        file_put_contents("/var/www/html/Project/status.txt", "2"); 
        fclose($fp);
        $fp = fopen('/var/www/html/Project/exit.txt', 'w');
        file_put_contents("/var/www/html/Project/exit.txt", "0");
        fclose($fp);
        header("refresh:2; url=signup.php"); 
    } else { // Create and initialises all the files for the proper working of the webpage. 
        echo "<script> swal('Sign up', 'You will be redirected to the sign up page', 'success');</script>";
        
        mkdir ("Project");

        $fp = fopen('/var/www/html/Project/users.txt', 'w');
        $old = umask(0);
        file_put_contents("/var/www/html/Project/users.txt", "/"."admin/");
        chmod("/var/www/html/Project/users.txt", 0777);
        umask($old);
        fclose($fp);
        
        $fp = fopen('/var/www/html/Project/status.txt', 'w');
        $old = umask(0);
        file_put_contents("/var/www/html/Project/status.txt", "2"); // "2" means that we are moving to the sign up webpage.
        chmod("/var/www/html/Project/status.txt", 0777);
        umask($old);
        fclose($fp);
        
        $fp = fopen('/var/www/html/Project/exit.txt', 'w');
        $old = umask(0);
        file_put_contents("/var/www/html/Project/exit.txt", "0"); // "0" means that we are not pressing the exit button.
        chmod("/var/www/html/Project/exit.txt", 0777);
        umask($old);
        fclose($fp);
        header("refresh:2; url=signup.php"); 
    }
}
    
 ?>
