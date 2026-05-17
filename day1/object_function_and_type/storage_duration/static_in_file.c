// static in file
static int company_internal_secret = 42; // Company secrets, not in the address book
static void internal_meeting() { ... } // Internal meetings, external no-notice

int public_api() { // Open APIs and upload company address books
    return company_internal_secret++;
}
