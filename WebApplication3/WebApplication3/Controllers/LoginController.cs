using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Http;
using System.Web;
using System.Web.Mvc;
using WebApplication3.Models;

namespace WebApplication3.Controllers
{
    public class LoginController : Controller
    {
        
        // GET: Login
        public ActionResult Index()
        {
            return View();
        }

        [ChildActionOnly]
        public ActionResult Login()
        {
            User model = new User();

            return PartialView("LoginView", model);
        }

        //public ActionResult Login1()
        //{
        //    IEnumerable<Student> students = null;

        //    using (var client = new HttpClient())
        //    {
        //        client.BaseAddress = new Uri("string");
        //        var responseTask = client.GetAsync("user");
        //        responseTask.Wait();

        //        var result = responseTask.Result;
        //        if (result.IsSuccessStatusCode)
        //        {

        //            var readTask = result.Content.ReadAsAsync<IList<Student>>();
        //            readTask.Wait();

        //            students = readTask.Result;
        //        }
        //        else
        //        {
        //            students = Enumerable.Empty<Student>();
        //            ModelState.AddModelError(string.Empty, "server error.plase contact adminstrator");
        //        }
        //    }
        //    return View(students);
        //}
    }
}