// This file was generated by gir (https://github.com/gtk-rs/gir)
// from gir-files
// DO NOT EDIT

use std::cmp;
use glib::translate::*;

glib::wrapper! {
    #[derive(Debug, Hash)]
    pub struct RepoFinderResult(Boxed<ffi::OstreeRepoFinderResult>);

    match fn {
        copy => |ptr| glib::gobject_ffi::g_boxed_copy(ffi::ostree_repo_finder_result_get_type(), ptr as *mut _) as *mut ffi::OstreeRepoFinderResult,
        free => |ptr| glib::gobject_ffi::g_boxed_free(ffi::ostree_repo_finder_result_get_type(), ptr as *mut _),
        type_ => || ffi::ostree_repo_finder_result_get_type(),
    }
}

impl RepoFinderResult {
    //#[doc(alias = "ostree_repo_finder_result_new")]
    //pub fn new(remote: &Remote, finder: &impl IsA<RepoFinder>, priority: i32, ref_to_checksum: /*Unknown conversion*//*Unimplemented*/HashTable TypeId { ns_id: 1, id: 0 }/TypeId { ns_id: 0, id: 28 }, ref_to_timestamp: /*Unknown conversion*//*Unimplemented*/HashTable TypeId { ns_id: 1, id: 0 }/TypeId { ns_id: 0, id: 9 }, summary_last_modified: u64) -> RepoFinderResult {
    //    unsafe { TODO: call ffi:ostree_repo_finder_result_new() }
    //}

    #[doc(alias = "ostree_repo_finder_result_compare")]
    fn compare(&self, b: &RepoFinderResult) -> i32 {
        unsafe { ffi::ostree_repo_finder_result_compare(self.to_glib_none().0, b.to_glib_none().0) }
    }
}

impl PartialEq for RepoFinderResult {
    #[inline]
    fn eq(&self, other: &Self) -> bool {
        self.compare(other) == 0
    }
}

impl Eq for RepoFinderResult {}

impl PartialOrd for RepoFinderResult {
    #[inline]
    fn partial_cmp(&self, other: &Self) -> Option<cmp::Ordering> {
        self.compare(other).partial_cmp(&0)
    }
}

impl Ord for RepoFinderResult {
    #[inline]
    fn cmp(&self, other: &Self) -> cmp::Ordering {
        self.compare(other).cmp(&0)
    }
}
